#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
//#include <format>
class BasePacket{
protected:
    virtual std::string serialize_body() = 0;
public:
    std::string serialize(){
        std::string body = serialize_body();
        //UPS 004
        std::ostringstream oss;
        oss << "UPS";
        oss << std::setw(3)<< std::setfill('0') << body.length();
        //oss <<std::format("{:0>3}",body.length());
        oss << body;
        return  oss.str();
    };
};
class LoginPacket : public BasePacket{
private:
    std::string username;
    std::string password;
protected:
    std::string serialize_body() override{
        return username + password;
    }
public:

    LoginPacket(const std::string& username, const std::string& password):
    username{username}, password{password}{}
};
int main() {
    LoginPacket l("martin","martinheslo");
    std::cout << l.serialize() << std::endl;
    /*
    FSHeader hdr;
    hdr.magic[0] = 'a';
    hdr.magic[1] = 'h';
    hdr.magic[2] = 'o';
    hdr.magic[3] = 'j';
    hdr.partition_size = 512 * 1024 * 1024;
    hdr.file_count = 15;

    //std::ofstream disk("disk.bin",std::ios::out | std::ios::binary);
    //disk.write(reinterpret_cast<const char*> (&hdr),sizeof (FSHeader));

    std::ifstream disk("disk.bin", std::ios::in | std::ios::binary);
    disk.read(reinterpret_cast<char*>(&hdr),sizeof (FSHeader));

    disk.seekg(0,std::ios::end);
    auto pos = disk.tellg();
    disk.seekg(0,std::ios::beg);
    */
    return 0;
}
