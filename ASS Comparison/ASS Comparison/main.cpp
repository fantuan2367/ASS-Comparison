#include <string>
#include "ASS.h"
int main() {
	string tra_file_name;
	string proof_file_name;
	cout << "������ļ���(����.ass��׺)"<<endl;
	getline(cin, tra_file_name);
	cout << "У�Ը��ļ���(����.ass��׺)"<<endl;
	getline(cin, proof_file_name);
	ASS tra_file(tra_file_name);
	ASS proof_file(proof_file_name);
	proof_file.compare(tra_file);
	proof_file.generate();
	cout << "��������������������������������" <<endl<< "����� �ļ���Ϊ���޸Ĳ���.ass��" << endl<<endl;
	return 0;
}
