#ifndef NUNBERSHOME_H
#define NUNBERSHOME_H


struct Sig {
    bool x1;
    bool x2;
    bool x3;
};
struct Blocks {
    bool or1=1;
    bool or2=1;
    bool or3=1;
    bool and4=0;
    bool and5=0;
    bool and6=0;
    bool or7= 0;
};
struct Outs {
    bool out1;
    bool out2;
    bool out3;
    bool out4;
    bool out5;
    bool out6;
    bool out7;
};
void inputValue(std::string aTitle, bool *pValue );
Sig EnterSig();
bool Answer_check(std::string qes,bool *out);
Blocks User_Changes( Blocks &pros);
Outs Process( Sig &x, Blocks &pros, Outs &ou );
#endif