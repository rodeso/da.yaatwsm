#ifndef YAATWSM_NODE_H
#define YAATWSM_NODE_H

#include "Include.h"

class Node {
    private:
        char type_; // s (source); t (sink); u (station)

        string name_; // reservoir name for s; city name for s; blank for u
        int id_; // common attribute
        string code_; // R_* for s; C_* for t; PS_* for u
        string municipality_; // municipality for s; blank for t and u
        int quantity_; // max delivery for s; population for t; blank for u
        double demand_; // demand for t; 0 for s and u


    public:
        //Constructor
        Node(char type, string name, int id, string code, string municipality, int quantity, double demand) {
            type_=type;
            name_=name;
            id_=id;
            code_= removeCarriageReturn(code);
            municipality_=municipality;
            quantity_=quantity;
            demand_=demand;
        }
        //Destructor
        ~Node() {}
        //Getters
        string getName() {return name_;}
        int getId() {return id_;}
        string getCode() {return code_;}
        string getMunicipality() {return municipality_;}
        int getQuantity() {return quantity_;}
        int getDemand() {return demand_;}

        //Type
        string getType() {
            if (type_ == 's')
                return "Source";
            if (type_ == 't')
                return "Sink";
            if (type_ == 'u')
                return "Station";
            if (type_ == 'd')
                return "Dummy";
        }
        bool isSource() {
            if (type_ == 's')
                return true;
            else
                return false;
        }
        bool isSink() {
            if (type_ == 't')
                return true;
            else
                return false;
        }
        bool isStation() {
            if (type_ == 'u')
                return true;
            else
                return false;
        }
        //Operator
        bool operator==(const Node& node) {
            return (code_ == node.code_);
        }
        //Util
        static string stringToHex(const std::string& input) {
            std::stringstream hexStream;
            hexStream << hex << uppercase << setfill('0');

            for (char ch : input) {
                hexStream << setw(2) << static_cast<int>(static_cast<unsigned char>(ch));
            }

            return hexStream.str();
        }
        static string removeCarriageReturn(const string& input) {
            size_t lastNonCR = input.find_last_not_of('\r');

            if (lastNonCR != string::npos) {
                return input.substr(0, lastNonCR + 1);
            } else {
                // String consists only of carriage returns, return an empty string
                return "";
            }
        }

    //Print
        void print() {
        if (this->isSource()) {
            cout << "Type: " << getType() << endl;
            cout << "Name: " << name_ << endl;
            cout << "ID: " << id_ << endl;
            cout << "Code: " << code_ << endl;
            cout << "Hex Code: " << stringToHex(code_) << endl;
            cout << "Municipality: " << municipality_ << endl;
            cout << "Max Delivery: " << quantity_ << endl;
            cout << "----------------------------------------" << endl;
        }
        if (this->isSource()) {
            cout << "Type: " << getType() << endl;
            cout << "Cidade: " << name_ << endl;
            cout << "ID: " << id_ << endl;
            cout << "Code: " << code_ << endl;
            cout << "Hex Code: " << stringToHex(code_) << endl;
            cout << "Demand" << demand_ << endl;
            cout << "Population: " << quantity_ << endl;
            cout << "----------------------------------------" << endl;
        }
        if (this->isStation()) {
            cout << "Type: " << getType() << endl;
            cout << "ID: " << id_ << endl;
            cout << "Code: " << code_ << endl;
            cout << "Hex Code: " << stringToHex(code_) << endl;
            cout << "----------------------------------------" << endl;
        }
    }
};

#endif //YAATWSM_NODE_H