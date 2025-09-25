#include <iostream>
#include <cstring>
using namespace std;

class TV {
public:
    static void action(char* s) { cout << s << endl; }
};

class Command {
public:
    virtual void execute() = 0;
    virtual char* getStatus() = 0;
};

class OnOffCommand : public Command {
public:
    OnOffCommand(bool s) : on(s) {}
    void execute() {
        on = on ? false : true;
        TV::action(getStatus());
    }
    char* getStatus() {
        char* str = new char[20];
        strcpy(str, "The device is ");
        strcat(str, (on == false ? "off" : "on"));
        return str;
    }
private:
    bool on;
};

class NextChannelCommand : public Command {
public:
    NextChannelCommand() {
        channel = 1;
    }
    void execute() {
        channel = (channel == 5) ? 1 : ++channel;
        TV::action(getStatus());
    }
    char* getStatus() {
        char* str = new char[30];
        strcpy(str, "The device is on channel ");
        switch (channel) {
        case 1: strcat(str, "1"); break;
        case 2: strcat(str, "2"); break;
        case 3: strcat(str, "3"); break;
        case 4: strcat(str, "4"); break;
        case 5: strcat(str, "5"); break;
        }
        return str;
    }
private:
    int channel;
};

class TVRemote { // Invoker
public:
    TVRemote() {
        buttons[0] = new OnOffCommand(false);
        buttons[1] = new NextChannelCommand();
    }
    ~TVRemote() {
        delete buttons[0];
        delete buttons[1];
    }
    void onPushed() {
        buttons[0]->execute();
    }
    void channelChanged() {
        buttons[1]->execute();
    }
private:
    Command* buttons[2];
};

int main() {
    TVRemote* tvr = new TVRemote;
    tvr->onPushed();
    tvr->channelChanged();
    tvr->channelChanged();
    tvr->channelChanged();
    tvr->onPushed();
    tvr->channelChanged();
    tvr->channelChanged();
    delete tvr;
    return 0;
}