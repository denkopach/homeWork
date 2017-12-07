#ifndef CREATEARRAY_H
#define CREATEARRAY_H


class CreateArray{
private:
    char** createArray;
public:
    CreateArray(int);
    char** returnArray();
    virtual ~CreateArray();
};
#endif // CREATEARRAY_H
