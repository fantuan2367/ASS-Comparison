#include "ASS.h"
#include <fstream>
#include <string>
vector<string> splitEx(const string& src, string separate_character)
{
	vector<string> strs;

	int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
	//if (!lastString.empty())
		strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
	return strs;
}
ASS::ASS(string file_name) {
	ifstream fin(file_name);
	string temp;
	vector<string> text;
	while (getline(fin,temp)) {
		if (temp == "[Events]")
			break;
		head_append(temp+ "\n");
	}
	head_append("[Events]\n");
	while (getline(fin, temp)) {
		text = splitEx(temp, ",");
		data.push_back(text);
	}
}
int ASS::get_length() {
	return data.size() - 1;
}
string ASS::get_sentence_at(int num) {
	return (data.at(num).size()==10)?(data.at(num).at(9)):("");
}
void ASS::comment_sentence_at(int num) {
	data[num][0] = "Comment: 0";
}
void ASS::head_append(string info) {
	head.append(info);
}
void ASS::compare(ASS tra_file) {
	int tra_length = tra_file.get_length();
	int proof_length = this->get_length();
	int line_temp=2;
	for (int i = 1; i < tra_length + 1; ++i) {
		for (int j = line_temp/2; j < proof_length + 1; ++j) {//The '+1' here is to take the title of the text part into consideration.
			//cout << "tra:" << tra_file.get_sentence_at(i) << "  proof:" << this->get_sentence_at(j) << endl;
			if (tra_file.get_sentence_at(i) == this->get_sentence_at(j)) {
				this->comment_sentence_at(j);
				line_temp = j;
				break;
			}
		}
	}
	make_comment();
}
void ASS::generate() {
	
	ofstream fout("修改部分.ass");
	fout << head;
	for (vector<vector<string>>::iterator it = data.begin(); it != data.end(); ++it) {
		string temp;
		temp.append((*it).at(0));
		for (int i = 1; i < (*it).size(); ++i) {
			temp.append(','+(*it).at(i));
		}
		fout << temp << endl;
	}
}
void ASS::make_comment() {
	for (int i = 1; i < data.size(); ++i) {
		(data[i][0] == "Comment: 0")?(data[i][0] = "Dialogue: 0"):(data[i][0] = "Comment: 0");
	}
}
