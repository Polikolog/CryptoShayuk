#include "solution.h"

Solution::Solution(QWidget *parent)
{

}

void Solution::getString(QString text, QString name)
{
    if(text == "")
        return;
    if(name == "name")
    {
        user.name = text;
    }
    else if(name == "password")
    {
        user.password = text;
    }
    if(user.name != "" && user.password != "")
            emit checkUser(user);
}
