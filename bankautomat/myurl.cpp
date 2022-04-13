#include "myurl.h"

myurl::myurl()
{
    base_url="http://localhost:3000";
    //base_url="http://ipv4.fiddler:3000";
}

QString myurl::getBase_url() const
{
    return base_url;
}
