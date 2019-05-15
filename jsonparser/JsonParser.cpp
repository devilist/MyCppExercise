//
// Created by admin on 2019/5/15.
//

#include "JsonParser.h"
#include <iostream>
#include "RapidJson/document.h"
#include "RapidJson/writer.h"
#include "RapidJson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

void parserJson(const char *pCharJson) {

    if (!pCharJson) return;

    rapidjson::Document d;
    d.Parse(pCharJson);

    cout << "d.IsObject(): " << d.IsObject() << endl;
    if (d.IsObject()) {
        const auto &object = d.GetObject();
        cout << "object name: " << typeid(object).name() << endl;
        cout << "object count: " << object.MemberCount() << endl;
        cout << "d.GetInt(): " << d.GetInt() << endl;
        cout << "d.GetString(): " << d.GetString() << endl;
        Value &value = d["stars"];
        cout << "stars: " << value.GetInt() << endl;
        auto iter = object.begin();
        while (iter != object.end()) {
            cout << "name: " << (*iter).name.GetString() << " value: " << (*iter).value.GetType() << endl;
            iter++;
        }
    }

    if (d.IsArray()) {

    }
}

void parserJson() {
    const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
    parserJson(json);

}
