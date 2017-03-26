#include <iostream>
#include <vector>
using namespace std;
class ASS
{
private:
	string head;//Head information including [Script Info], [Aegisub Project Garbage] and [V4+ Styles].
	vector<vector<string>> data;//[Events]
public:
	ASS(string file_name);
	int get_length();
	string get_sentence_at(int num);
	void comment_sentence_at(int num);
	void head_append(string info);
	void compare(ASS tra_file);//Compare two ass files and build up a new ASS object.
	void generate();//Generate a new ass file.
	void make_comment();
};

