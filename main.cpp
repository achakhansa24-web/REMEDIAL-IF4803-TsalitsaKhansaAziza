#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack S_Aksi, S_Redo;
    int damage = 0;

    create_stack(S_Aksi);
    create_stack(S_Redo);

    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "DEFENSE");
    manageAction(S_Aksi, S_Redo, "UNDO");
    manageAction(S_Aksi, S_Redo, "REDO");

    totalDamage(S_Aksi, damage);

    cout << "Total Damage: " << damage << endl;
    return 0;
}
