#include <stdio.h>

#include "rte_app1_state_manage.h"
#include "rte_app1_can_rx.h"

int main()
{
    printf("Power ON, IG ON, ECU Software Start to Run!\n");

    StateManagerMain();

    return 1;
}
