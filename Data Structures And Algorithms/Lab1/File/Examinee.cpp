#include "Examinee.h"

Examinee readExaminee(string line_info)
{
    Examinee temp;

    Tokenizer tk;

    tk.split(line_info, ",");

    temp.id = tk.tokens[0];
    temp.name = tk.tokens[1];
    temp.math = stoi(tk.tokens[2]);
    temp.literature = stoi(tk.tokens[3]);
    temp.physic = stoi(tk.tokens[4]);
    temp.chemistry = stoi(tk.tokens[5]);
    temp.biology = stoi(tk.tokens[6]);

    return temp;
}
