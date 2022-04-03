#include<iostream>
#include<string>

using namespace std;

int main() {
    string msg, key, newKey, encryptedMsg, decryptedMsg, x;

    //평문, 키 입력
    cout << "평문 : ";
    getline(cin, msg, '\n');
    cout << "키 : ";
    getline(cin, key, '\n');

    //키 배열
    for (int i = 0, j = 0; i < msg.length(); ++i, ++j) {
        if (j == key.length())
            j = 0;
        x = key[j];
        newKey.append(x);
    }

    //암호화
    for (int i = 0; i < msg.length(); ++i) {
        x = ((msg[i] + newKey[i]) % 26) + 'A';
        encryptedMsg.append(x);
    }

    //복호화
    for (int i = 0; i < msg.length(); ++i) {
        x = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
        decryptedMsg.append(x);
    }

    cout << "\n암호화 문장 : " << encryptedMsg;
    cout << "\n복호화 문장 : " << decryptedMsg;
}