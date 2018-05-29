//
// Created by zengp on 2018/2/1.
//

#include <iostream>
#include <ctime>
#include "h/chapter12.h"
#include "class/queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

void testqueue();

void exercise12()
{
//    testqueue();
}

void testqueue()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // 初始化 random rand()
    // srand():给rand()提供种子seed
    // 如果srand每次输入的数值是一样的，那么每次运行产生的随机数也是一样的
    // time(nullptr)将使得种子为一个不固定的数， 这样产生的随机数就不会每次执行都一样
    std::srand((unsigned) std::time(nullptr));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue:";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour; // 平均几分钟来一个人

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wate_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle); //到达时间
                line.enqueue(temp); // 入队
            }
        }

        if (wate_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);  // 出队
            wate_time = temp.ptime();
            line_wait += cycle - temp.when();

            served++;
        }
        if (wate_time > 0)
            wate_time--;
        sum_line += line.queuecount();
    }

    if (customers > 0)
    {
        cout << " customers accepted: " << customers << endl;
        cout << "   customers served: " << served << endl;
        cout << "          turnaways: " << turnaways << endl;
        cout << " average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "  average wait time: " << (double) line_wait / served << " mintues\n";
    } else
    {
        cout << "No customers.\n";
    }
    cout << "Done.\n";
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
