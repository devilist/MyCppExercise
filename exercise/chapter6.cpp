//
// Created by zengp on 2018/1/17.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include "h/chapter6.h"

using namespace std;

void writeToFile(string);

void readFromFile(string);

void delaySomeSecond(int);

void exercise6()
{
    string file_name = "exercise6_file.txt";

//    writeToFile(file_name);
//    readFromFile(file_name);
}


void writeToFile(string fileName)
{
    char automobile[50];
    int year;
    double a_price;
    double b_price;

    ofstream outFile;
    outFile.open(fileName);

    cout << "Enter the make and model of automobile:";
    cin.getline(automobile, 50);
    cout << "Enter the model year:";
    cin >> year;
    cout << "Enter the original asking price:";
    cin >> a_price;
    b_price = 0.913 * a_price;

    // write to file
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << b_price << endl;

    outFile.close();
}

void readFromFile(string fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        cout << "can not find the file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    string tip = "\nbegin read from the file \"" + fileName + "\" \nplease wait...";
    for (int i = 0; i < tip.length(); ++i)
    {
        cout << tip[i];
        delaySomeSecond(150);
    }

    cout << endl << endl;
    delaySomeSecond(2000);

    char read;
    inFile.get(read);
//    inFile >> read;
    do
    {
        cout << read;
        delaySomeSecond(80);

    } while (!inFile.get(read).eof());

    delaySomeSecond(1000);
    cout << endl;
    cout << "\nread finish!" << endl << endl;

    inFile.close();
}

void delaySomeSecond(int msec)
{
    float sec = msec * 1.0f / 1000;

    clock_t delay = (int) (sec * CLOCKS_PER_SEC);
    clock_t start = clock();
    while (clock() - start < delay);
}









