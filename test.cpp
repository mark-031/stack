#define STACKDEBUG
#include<stack.cpp>

int test1()
{
    stack_t* t_stk = nullptr;

    if (StackInit(t_stk, -1) == 0)
        return 1;

    return 0;
}

int test2()
{
    stack_t* t_stk = nullptr;

    int item = 0;
    StackInit(t_stk, 8);
    StackPush(t_stk, item);
    StackPop(t_stk, &item);

    if (item != 10)
        return 1;
    
    return 0;
}

int test3()
{
    stack_t* t_stk = nullptr;

    StackInit(t_stk, 8);
    t_stk->canary = ~t_stk->canary;

    if(StackOk(t_stk) != BadCanary)
        return 1;
    
    return 0;
}

int test()
{
    stack_t* t_stk = nullptr;

    // Wrong init
    if (test1())
        return 1;
    
    // Push and Pop check
    if (test2())
        return 2;
        
    // Canary attack
    if (test3())
        return 3;

}