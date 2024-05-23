#include <iostream>
#include <string>
using namespace std;

class PC {
protected:
    string box = "";
    string processor = "";
    string mainboard = "";
    string hdd = "";
    string memory = "";

public:
    virtual void SetBox() = 0;
    virtual void SetProcessor() = 0;
    virtual void SetMainBoard() = 0;
    virtual void SetHdd() = 0;
    virtual void SetMemory() = 0;

    void ShowPC() 
    {
        cout << "Box: " << box << "\nProcessor: " << processor << "\nMainBoard: " << mainboard << "\nHDD: " << hdd << "\nMemory: " << memory;
        cout << "\n\n";
    }
};

class OfficePC : public PC {
public:
    void SetBox() override 
    {
        box = "BlackBox";
    }
    void SetProcessor() override
    {
        processor = "AMD Athlon II X4 840 (3.1 GHz)";
    }
    void SetMainBoard() override 
    {
        mainboard = "AMD A58 FCH (Bolton D2)";
    }
    void SetHdd() override 
    {
        hdd = "Seagate Desktop HDD 7200.12 500GB";
    }
    void SetMemory() override
    {
        memory = "4 Gb DDR3-1600 MHz";
    }
};

class HomePC : public PC {
public:
    void SetBox() override
    {
        box = "SilverBox";
    }
    void SetProcessor() override
    {
        processor = "Intel Core i7-4790 (3.6 GHz)";
    }
    void SetMainBoard() override
    {
        mainboard = "Intel B85";
    }
    void SetHdd() override
    {
        hdd = "Western Digital Elements 1.5TB";
    }
    void SetMemory() override
    {
        memory = "16 GB DDR3-1600";
    }
};

class GamingPC : public PC {
public:
    void SetBox() override 
    {
        box = "RGBBox";
    }
    void SetProcessor() override
    {
        processor = "Intel Core i9-9900K (3.6 GHz)";
    }
    void SetMainBoard() override
    {
        mainboard = "MSI Z390-A PRO";
    }
    void SetHdd() override
    {
        hdd = "Samsung 970 EVO 1TB NVMe";
    }
    void SetMemory() override
    {
        memory = "32 GB DDR4-3200";
    }
};

class Creator 
{
public:
    virtual PC* FactoryMethod() = 0;
};

class CreatorHomePC : public Creator {
public:
    PC* FactoryMethod() override
    {
        PC* pc = new HomePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainBoard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

class CreatorOfficePC : public Creator {
public:
    PC* FactoryMethod() override 
    {
        PC* pc = new OfficePC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainBoard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

class CreatorGamingPC : public Creator {
public:
    PC* FactoryMethod() override
    {
        PC* pc = new GamingPC();
        pc->SetBox();
        pc->SetProcessor();
        pc->SetMainBoard();
        pc->SetMemory();
        pc->SetHdd();
        return pc;
    }
};

void Factory(Creator * *creators, int size)
{
    for (int i = 0; i < size; i++)
    {
        PC* pc = creators[i]->FactoryMethod();
        pc->ShowPC();
    }
}

int main() {
    Creator* creators[3];
    creators[0] = new CreatorHomePC();
    creators[1] = new CreatorOfficePC();
    creators[2] = new CreatorGamingPC();
    Factory(creators, 3);
    delete creators[0];
    delete creators[1];
    delete creators[2];
}