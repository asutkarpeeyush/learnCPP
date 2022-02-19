#include <iostream>
#include <cstring>
#include "fun.h"
#include "Log.h"

#define LOG(x) std::cout << x << std::endl;

void IncrementWithPointer(int *value) {
    (*value)++;
}

void IncrementWithReference(int &value) {
    value++;
}

class Player {
public:
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }

    virtual std::string GetName() {
        return "Player";
    }
};

class PlayerWithName : public Player {
private:
    std::string m_Name;
public:
    PlayerWithName(const std::string &name) : m_Name(name) {}

    void PrintName() {
        std::cout << m_Name << std::endl;
    }

    std::string GetName() override{
        return m_Name;
    }
};

struct PlayerStruct {
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

static int s_Variable = 5; // this is visible only to the cpp file
// no one can use "extern" to refer to this. Same thing for function
// If a header file has static variable, it gets included (copied) in every cpp file where
// that header is included. Statics outside class are not linked across translation units (across separate files)

// static struct example
struct StaticStructExample {
    static int x, y;

    static void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

int StaticStructExample::x;
int StaticStructExample::y;

enum EnumExample : char {
    // the type of value c
    // an be also specified
//    A, B, C
    A = 0, B = 2, C = 5
};

int main() {
    int a;
//    std::cin >> a ;
//    std::cout << "Hello World " <<  a << std::endl;

    // ------------------- Header file ------------------------ //
    fun();

    // ------------------- Pointers ------------------------ //
//    // On stack
//    int var = 100;
//    int* ptr = &var;
//    *ptr = 10;
//    LOG(var);
//
//    // In Heap
//    char* buffer = new char[8];
//    memset(buffer, 0, 8);
//    buffer[4] = 'b';
//    char** double_ptr = &buffer;
//    delete[] buffer;

    // ------------------- References ------------------------ //
//    int aa = 5;
//    int bb = 6;
//    int& ref = aa;
//    ref = 2;
//    ref = bb; // this will set value of aa to bb
//    IncrementWithPointer(&aa);
//    IncrementWithReference(aa);
//    LOG(aa); // aa incremented twice
//    LOG(bb);

    // ------------------- Structs ------------------------ //
//    // Struct exists if everything needs to be public inside a class
//    // Also for backward compatibility
//    PlayerStruct player;
//    player.x = 5;
//    player.y = 5;
//    player.speed = 2;
//    player.Move(3, 3);
//    LOG(player.x);

    // ------------------- Classes ------------------------ //
//    Player player;
//    player.x = 5;
//    player.y = 5;
//    player.speed = 2;
//    player.Move(3, 3);
//    LOG(player.x);

    // ------------------- Using LOG class ------------------------ //
//    Log log;
//    log.SetLevel(Log::WarnLevel);
//    log.Error("Hello");
//    log.Warn("Hello");
//    log.Info("Hello");
//
//    Log log1(Log::ErrorLevel);
//    log.Error("Hello1");
//    log.Warn("Hello1");
//    log.Info("Hello1");

    // ------------------- Static Outside class ------------------------ //
//    LOG(s_Variable);

    // ------------------- Static Inside class and structs ------------------------ //
//    StaticStructExample sse;
//    sse.x = 2;
//    sse.y = 3;
//
//    StaticStructExample sse1;
//    sse1.x = 5;
//    sse1.y = 8;
//
//    StaticStructExample::x = 10;
//    StaticStructExample::y = 20; // correct way to call static variables
//    sse.Print();
//    sse1.Print();
//    StaticStructExample::Print(); // static method can access static variables and not non-static ones
//    // because the static method doesn't have a class instance, it's like writing a method outside the class
//    // but is kept inside the class for logical grouping

    // ------------------- Enums ------------------------ //
//    EnumExample value = B;
//    if (value == B) {
//        LOG(value);
//    }
//    LOG(EnumExample::A);

    // ------------------- Inheritance with virtual fucntions------------------------ //
    LOG(sizeof(Player));
    LOG(sizeof(PlayerWithName));
    Player player;
    LOG(player.GetName());
    PlayerWithName* playerWithName = new PlayerWithName("Piyush");
    playerWithName->PrintName();
    playerWithName->Move(1, 2);
    LOG(playerWithName->GetName());

    Player* player1 = playerWithName;
    LOG(player1->GetName()); // this should call getName of playerWithName, so the getName in
    // base class is marked as virtual (some vtable magic). Also mark the overridden function
    // in sub-class as "override". To mark the function as override, the base function should be
    // marked as "virtual"
    // There's an increase in memory space due to vtable and also performance due to accessing vtables
}
