#include <string>
#include "ASS.h"
int main() {
	string tra_file_name;
	string proof_file_name;
	cout << "翻译稿文件名(包含.ass后缀)"<<endl;
	getline(cin, tra_file_name);
	cout << "校对稿文件名(包含.ass后缀)"<<endl;
	getline(cin, proof_file_name);
	ASS tra_file(tra_file_name);
	ASS proof_file(proof_file_name);
	proof_file.compare(tra_file);
	proof_file.generate();
	cout << "————————————————" <<endl<< "已完成 文件名为“修改部分.ass”" << endl<<endl;
	return 0;
}
