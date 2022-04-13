#ifndef MYURL_H
#define MYURL_H

#include <qstring.h>



class myurl
{
public:
    myurl();
    QString getBase_url() const;
private:
    QString base_url;
};

#endif // MYURL_H
