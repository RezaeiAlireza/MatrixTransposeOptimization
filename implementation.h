//DON'T MODIFY THIS FUNCTION
void naive(int *src, int *dst, int SIZE)
{
    for(int i=0; i < SIZE; i++)
        for(int j=0; j < SIZE; j++)
            dst[(j * SIZE) + i] = src[(i * SIZE) + j];
}

//DON'T MODIFY THE HEADER OF THE FUNCTION
void aware(int *src, int *dst, int SIZE)
{
    int JUMPSTP = 8;
    for(int row=0; row < SIZE; row+=JUMPSTP)
        for(int col=0; col < SIZE; col+=JUMPSTP)
            for(int innerrow=row; innerrow < row+JUMPSTP; innerrow++)
                for(int innercol=col; innercol < col+JUMPSTP; innercol++)
                    dst[(innercol * SIZE) + innerrow] = src[(innerrow * SIZE) + innercol];
}

//DON'T MODIFY THE HEADER OF THE FUNCTION
int mortongen(int celladdr)
   {
    celladdr = celladdr & 0x55555555;
    celladdr = (celladdr | (celladdr >> 1)) & 0x33333333;
    celladdr = (celladdr | (celladdr >> 2)) & 0x0F0F0F0F;
    celladdr = (celladdr | (celladdr >> 4)) & 0x00FF00FF;
    celladdr = (celladdr | (celladdr >> 8)) & 0x0000FFFF;
      return celladdr;
    }

void oblivious(int *src, int *dst, int SIZE)
{   
    for(int celladdr=0; celladdr < SIZE*SIZE; celladdr++)
    {
        int row = mortongen(celladdr);
        int col = mortongen(celladdr >> 1);
        dst[(col * SIZE) + row] = src[(row * SIZE) + col];
    }
}

//DON'T MODIFY THE HEADER OF THE FUNCTION
void optimized(int *src, int *dst, int SIZE)
{
    
    int JUMPSTP = 8;   
    for (int celladdr = 0; celladdr < SIZE*SIZE; celladdr += JUMPSTP*JUMPSTP) {    
        int row = mortongen(celladdr);
        int col = mortongen(celladdr >> 1);
        for (int i = row; i < row + JUMPSTP; i++) {
            for (int j = col; j < col + JUMPSTP; j++) {
                dst[(j * SIZE) + i] = src[(i * SIZE) + j];
            }
        }
    }
}