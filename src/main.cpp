#include <iostream>
#include <string>
#include <array>
#include "fun.h"
#include "Log.h"

#define LOG(x) std::cout << x << std::endl;

void IncrementWithPointer(int *value) {
    (*value)++;
}

void IncrementWithReference(int &value) {
    value++;
}

// Interface utils
class Printable {
public:
    virtual std::string GetClassName() = 0; // = 0 makes it a pure virtual function
};
void Print(Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}

class AClass : public Printable {
public:
    std::string GetClassName() override {
        return "AClass";
    }
};

// Class utils
class Player : public Printable{
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

    std::string GetClassName() override {
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

    std::string GetClassName() override {
        return "PlayerWithName";
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

void PrintCPPString(std::string basicString);

int StaticStructExample::x;
int StaticStructExample::y;

enum EnumExample : char {
    // the type of value c
    // an be also specified
//    A, B, C
    A = 0, B = 2, C = 5
};

void AlterCPPString(std::string& cppString) {
    cppString += "hhh";
}


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

    // ------------------- Inheritance with virtual functions------------------------ //
//    LOG(sizeof(Player));
//    LOG(sizeof(PlayerWithName));
//    Player player;
//    LOG(player.GetName());
//    PlayerWithName* playerWithName = new PlayerWithName("Piyush");
//    playerWithName->PrintName();
//    playerWithName->Move(1, 2);
//    LOG(playerWithName->GetName());
//
//    Player* player1 = playerWithName;
//    LOG(player1->GetName()); // this should call getName of playerWithName, so the getName in
//    // base class is marked as virtual (some vtable magic). Also mark the overridden function
//    // in sub-class as "override". To mark the function as override, the base function should be
//    // marked as "virtual"
//    // There's an increase in memory space due to vtable and also performance due to accessing vtables

    // ------------------- Interface i.e pure virtual functions------------------------ //
//    Player* p = new Player();
//    Print(p);
//
//    PlayerWithName* p1 = new PlayerWithName("Piyush");
//    Print(p1);
//
//    AClass* aClass = new AClass();
//    Print(aClass);

    // ------------------- Visibility------------------------ //
    // Default visibility in class is private and struct is public
    // private - only the class or friends
    // protected - the class and subclasses but not outside of class and subclasses
    // public - from everywhere

    // ------------------- Arrays ------------------------ //
//    int example[5];
//    int* examplePtr = example;
//    example[0] = 3;
//    *(examplePtr + 2) = 7;
//    *(int*)((char*)examplePtr + 8) = 10; //  this is similar to above line
//    example[4] = 6;
//
//    int* anotherArr = new int[5]; // this is created on heap and need to be destroyed
//    // or need will be deleted when program ends (not the scope but program)
//    // the use case is when a function has to return an array, it has to live outside the scope
//    // by creating on heap has a downside which is jumping around memory and that is a performance hit
//
//    // there is no method to get the size of array if it's created on heap
//    anotherArr[3] = 6;
//
//    LOG(sizeof(example)/sizeof(int));
//    delete[] anotherArr;
//
//    // correct way to keep size
//    static const int arrSize = 5;
//    int arr[arrSize];
//
//    // cpp11
//    std::array<int, 50> cppArray;
//    LOG(cppArray.size());
//
//    // 2d array
//    int twodArr[3][2] = {{1,2}, {3,4}, {5,6}};
//    LOG(twodArr[1][1]);
//
//    LOG(example);

    // ------------------- Strings ------------------------ //
    // char* name = "Piyush"; //\o is null termination
    // // *name = 'g'; // not allowed in some compilers
    // // https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-char-s-initialized-with-a
    // LOG(name);

    char name2[5] = {'P', 'i', 'y', 'u', '\0'};
    LOG(name2);

    std::string cppName = "Cherno";
    cppName += " Hello";
    // std::string cppName = std::string("Cherno") +  "Hello";
    bool contains = cppName.find("no") != std::string::npos;
    LOG(contains);
    LOG(cppName.size());
    LOG(cppName);

    // always pass strings by const reference or reference
    AlterCPPString(cppName);
    LOG(cppName);

    LOG("Hello how are you?")
}