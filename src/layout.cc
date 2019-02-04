#include "layout.hh"

Layout::Layout(int n)
{
    assert(n > 0);
    assert(n < 10);
    layout_ = std::vector<int>(n*n);
    size_ = n;
    for(int i = 0; i < size_ ; i++)
    {
        for(int j = 0 ; j < size_; j++)
        {
            layout_[i * size_ + j] = i * size_ + j;
        }
    }
}

void Layout::dump()
{
    for(int i = 0; i < size_ ; i++)
    {
        for(int j = 0 ; j < size_; j++)
        {
            if(layout_[i*size_+j] == 0)
            {
                std::cout << "    -";
                continue;
            }
            if(i * size_ + j < 10)
                std::cout << std::setw(4);
            else
                std::cout << std::setw(3);
            std::cout << " " << layout_[i * size_ + j];
        }
        std::cout << "\n";
    }
}

//void swap(mysize a, mysize b);
