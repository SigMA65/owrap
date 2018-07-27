#include "message.h"


int main()
{
    setRusLocale();
    message("Это обычное сообщение");
    dMessage("Это отладочное сообщение");
    error("Это ошибка");

    return 0;
}


