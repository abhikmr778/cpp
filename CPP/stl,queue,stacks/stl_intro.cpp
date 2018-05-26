#include <iostream>
#include <algorithm>
using namespace std;

class movie{
public:
    string title;
    int release_year;
    void print(){
        cout<<title<<" "<<release_year<<endl;
    }
};

bool compare(movie a, movie b){
    //sorting criteria
    if(a.release_year < b.release_year){
        return true;
    }else{
        return false;
    }
}

bool comparetitle(movie a, movie b){
    if(a.title < b.title){
        return true;
    }else{
        return false;
    }
}

int main(){
    movie marr[] = {
        {"baghi 2", 2010},
        {"3 idiots", 2014},
        {"interstellar", 2014},
        {"bahubali 2", 2017},
        {"shawshank redemption", 1996},
        {"wolf of wallstreet", 2013},
        {"titanic", 1997}
    };

    int n = sizeof(marr)/sizeof(movie);
    sort(marr ,marr+n, comparetitle);
    // int arr[] = {5,4,3,2,1};
    // int n = 5;

    // sort(arr, arr+5);
    for (int i = 0; i < n; i++)
    {
        marr[i].print();
    }
    return 0;
}