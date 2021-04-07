
#ifndef MAIN_H

#define MAIN_H

struct Sig {
    bool x1;
    bool x2;
    bool x3;
};
struct Blocks {
    bool or1 = 1;
    bool or2 = 1;
    bool or3 = 1;
    bool and4 = 0;
    bool and5 = 0;
    bool and6 = 0;
    bool or7 = 0;
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

/**
 * Input value function.
 *
 * @param aTitle title input (IN)
 * @param pValue pointer to value (OUT)
 */
void inputValue(std::string aTitle, bool* pValue);

/**
 *
 * @return
 */
Sig EnterSig();

/**
 *
 * @param qes
 * @param out
 * @return
 */
bool AnswerCheck(std::string qes, bool* out);

/**
 *
 * @param pros
 * @return
 */
Blocks UserChanges(Blocks& pros);

/**
 *
 * @param x
 * @param pros
 * @param ou
 * @return
 */
Outs Process(Sig& x, Blocks& pros, Outs& ou);

#endif
