

void init_maps(int map1[10][10],int map2[10][10],int ships[14]);;


bool place_ship(int map1[10][10],int row, int column, char orientation,int length, int ship);

void map_setup(int map1[10][10],int map2[10][10],int ships[14], int player);

int attack(int map1[10][10],int row, int column);

void new_game(int map1[10][10],int map2[10][10],int ships[14]);

int make_move(int map1[10][10],int map2[10][10], int * health1, int * health2, int ships[14],int player, char * rx,int  *ry);

void start_turn(int map1[10][10],int map2[10][10], int health1, int health2, int ships[14],int round, int target,int player, char x,int y);
