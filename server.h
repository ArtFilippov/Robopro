enum
{
    NUMBER_OF_MATRICES = 5,
    N = 6
};

struct Server
{
    double det[NUMBER_OF_MATRICES];
    short cyclic_iterator; // указывает на самую старую запись в det
    short matrices;
};

void run(struct Server *server);
void form_response(char *buff);