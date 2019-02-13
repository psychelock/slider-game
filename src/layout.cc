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
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(begin(layout_),end(layout_),std::default_random_engine(seed));
    for(int i = 0; i < size_ ; i++)
    {
        for(int j = 0 ; j < size_; j++)
        {
            if(layout_[i * size_ + j] == 0)
               blank_ = i * size_ + j; 
        }
    }
}

std::size_t num(std::size_t num)
{
    std::size_t res=0;
    while(num > 0)
    {
        num/=10;
        res++;
    }
    return res;
}

void Layout::dump()
{
    for(int i = 0; i < size_ ; i++)
    {
        for(int j = 0 ; j < size_; j++)
        {
        std::cout << "  |" ;
        std::cout << std::setw(num(size_)+2);
            if(layout_[i*size_+j] == 0)
            {
                std::cout << "-";
                continue;
            }
            std::cout << layout_[i * size_ + j];
        }
        std::cout << "  |";
        std::cout << "\n";
    }
}

int Layout::move(char c)
{
    switch (c)
    {
        case UP:
            move_up();
            return 1;
            break;
        case DOWN:
            move_down();
            return 1;
            break;
        case LEFT:
            move_left();
            return 1;
            break;
        case RIGHT:
            move_right();
            return 1;
            break;
        case QUIT:
            return 2;
            break;
        default:
            std::cout << "Invalid Input\n";
            return 1;
    }
}

void Layout::my_swap(int a, int b)
{
    auto tmp = layout_[a];
    layout_[a] = layout_[b];
    layout_[b] = tmp;
}

void Layout::move_up()
{
    if(blank_ > size_-1)
    {
        my_swap((blank_), (blank_ - size_));
        blank_ = blank_ - size_;
    }
}
void Layout::move_down()
{
    if(blank_ < (size_ * size_)-size_)
    {
        my_swap((blank_), (blank_ + size_));
        blank_ = blank_ + size_;
    }
}
void Layout::move_left()
{
    if(blank_ % size_ != 0)
    {
        my_swap((blank_), (blank_ - 1));
        blank_ = blank_ - 1;
    }
}
void Layout::move_right()
{
    if(blank_ % size_ != size_ -1)
    {
        my_swap((blank_), (blank_ + 1));
        blank_ = blank_ + 1;
    }
}

int Layout::win_cond()
{
    for(int i = 0; i < size_ ; i++)
    {
        for(int j = 0 ; j < size_; j++)
        {
            if(layout_[i * size_ + j] != i * size_ + j)
                return 1;
        }
    }
    return 0;
}
