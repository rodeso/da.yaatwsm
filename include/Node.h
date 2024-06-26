
#ifndef YAATWSM_NODE_H
#define YAATWSM_NODE_H

#include "Include.h"

/**
 * @brief Class that represents the various types of Nodes which the Vertexes may represent in the graph: Cities (sinks), Pumping Stations and Reservoirs (Sources).
 */

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
        /**
        * @brief Constructor of the Node. The type of the Node depends on the values of its atributes.
        */
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
            
            throw invalid_argument("Invalid type_ value: " + to_string(type_));
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
        /**
        * @brief Function that prints the information of the various types of Nodes that are being made according to the chosen data folder.
        */
        void print() {
        if (this->isSource()) {
            cout << "Type: " << getType() << "   Name: " << name_ << "   ID: " << id_ << "   Code: " << code_ << "   Hex Code: " << stringToHex(code_) << "   Municipality: " << municipality_ << "   Max Delivery: " << quantity_ << endl;
            cout << string(LINE_SIZE_, '-') << endl;
        }
        if (this->isSink()) {
            cout << "Type: " << getType() << "   City: " << name_ << "   ID: " << id_ << "   Code: " << code_ << "   Hex Code: " << stringToHex(code_) << "   Demand: " << demand_ << "   Population: " << quantity_ << endl;
            cout << string(LINE_SIZE_, '-') << endl;
        }
        if (this->isStation()) {
            cout << "Type: " << getType() << "   ID: " << id_ << "   Code: " << code_ << "   Hex Code: " << stringToHex(code_) << endl;
            cout << string(LINE_SIZE_, '-') << endl;
        }

    }
};

#endif //YAATWSM_NODE_H