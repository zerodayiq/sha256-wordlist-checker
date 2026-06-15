#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

/*
    هذه الدالة وظيفتها:
    تحويل أي نص (string) إلى SHA-256 hash بصيغة hex
*/
string sha256(const string &input) {
    // مصفوفة لتخزين نتيجة الهاش (32 بايت = 256 bit)
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // حساب SHA-256 للنص المدخل
    SHA256((unsigned char*)input.c_str(), input.size(), hash);

    /*
        تحويل الناتج من bytes إلى string hex
        لأن الناتج الخام غير مقروء للبشر
    */
    stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        // تحويل كل بايت إلى رقم hex من خانتين
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    // إرجاع الهاش النهائي كنص
    return ss.str();
}

int main() {

    // المتغير الذي يخزن الهاش الهدف الذي ندور عليه
    string target_hash;

    cout << "Enter SHA-256 hash: ";
    cin >> target_hash;

    /*
        فتح ملف wordlist الذي يحتوي على كلمات محتملة
        كل كلمة سيتم تجربتها كـ "password"
    */
    ifstream file("wordlist.txt");

    string word;

    // إذا الملف غير موجود، أوقف البرنامج
    if (!file) {
        cout << "wordlist.txt not found!\n";
        return 1;
    }

    /*
        قراءة الملف سطر سطر (كل سطر = كلمة محتملة)
    */
    while (getline(file, word)) {

        // حساب SHA-256 للكلمة الحالية
        string hashed = sha256(word);

        /*
            طباعة الكلمة التي يتم تجربتها (debug فقط)
            ⚠ هذا يبطّئ البرنامج بشكل كبير إذا كانت wordlist كبيرة
        */
        cout << "Trying: " << word << endl;

        /*
            مقارنة الهاش الناتج مع الهاش المطلوب
            إذا تطابق → وجدنا كلمة المرور
        */
        if (hashed == target_hash) {
            cout << "\n[+] Password FOUND: " << word << endl;
            return 0; // إنهاء البرنامج فورًا
        }
    }

    /*
        إذا انتهى الملف ولم نجد أي تطابق
    */
    cout << "\n[-] Password not found in wordlist.\n";

    return 0;
}