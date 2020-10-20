#ifndef _EXAMINEE_H_
#define _EXAMINEE_H_

#include <iostream>
#include "tokenizer.h"
#include <string>

using namespace std;

struct Examinee
{
	string id;
	string name;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};

Examinee readExaminee(string line_info);

#endif