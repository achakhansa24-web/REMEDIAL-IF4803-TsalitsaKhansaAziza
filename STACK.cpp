#include "stack.h"

void create_stack(Stack &S) {
    S.top = -1;
}

bool is_Empty(Stack S) {
    return S.top == -1;
}

bool is_full(Stack S) {
    return S.top == N_STACK - 1;
}

void push(Stack &S, infotype x) {
    if (!is_full(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S){
   infotype x;

    if (is_Empty(S)){
      return "";
    } else{
        x = S.info[S.top];
        S.top--;
        return x;
    }
}

void emptyStack(Stack &S) {
    S.top = -1;
}

void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi) {
    infotype temp;
    if (aksi == "UNDO") {
        temp = pop(S_Aksi);
        if (temp != ""){
            push(S_Redo, temp);
        }
    }else if (aksi == "REDO") {
        temp = pop(S_Redo);
        if (temp != "") {
            push(S_Aksi, temp);
        }
    }else{
        push(S_Aksi, aksi);
        emptyStack(S_Redo);
    }
}

void totalDamage(Stack &S, int &damage) {
    infotype aksi;
    damage = 0;
    while (!is_Empty(S)) {
        aksi = pop(S);
        if (aksi == "ATTACK"){
            damage += 30;
        }else if (aksi == "DEFENSE"){
            damage += 5;
        }
    }
}
