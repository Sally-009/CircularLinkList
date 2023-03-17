#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *link;
};

class CLL{
    private:
    Node *first, *last; // 先頭と末尾
    int size;
    
    public:
    //CONSTRUCTOR
    // 空のリストを作る
    CLL(){
        first = last= nullptr;
        size = 0;
    }
    
    //DESTRUCTOR
    // ノードをすべて削除する
    ~CLL(){
        Node *p = first;    // 現在地
        Node *q = nullptr;  // 前のノード
        
        cout << endl;
        cout << "Destructor:" << endl;
        
        // ノードをすべて削除する
        for(int i = 1; i < size + 1; i++)   //qを消すから、1回余分に繰り返す
        {
            q = p;
            p = p->link;
            cout << q->data << " ";
            delete q;
        }
        
        cout << "deleted." << endl;
    }
    
    // ノードを追加する
    void Append(int val){
        //新規ノードの作成
        Node *newNode = new Node;
        newNode -> data = val;
        
        //ノードのlinkを設定
        //リストが空のとき
        if(first == nullptr)
        {
            // 先頭も末尾も自身
            first = newNode;
            last = newNode;
            // 自分自身とリンクする
            newNode -> link = first;
        }
        // リストが空でないとき
        else
        {
            last -> link = newNode; // 末尾と新規ノードをリンクする
            last = newNode;         // 末尾を更新
            newNode -> link = first; // 先頭とリンクする
        }
        
        //サイズを更新
        size++;
    }
    
    // n番目のノードを削除する
    void Delete(int n)
    {
        Node *p = first;    // 現在地
        Node *q = nullptr;  // 前のノード
        
        // nが有効か見る
        if(n < 0 || n > size)
        {
            cout << n << " is an invalid position." << endl;
            return;
        }
        
        
        // 先頭（n=1)のとき
        if(n == 1)
        {
            cout << "First Node: " << p->data << " deleted." << endl;
            first = p->link;    // firstを次のノードにリンクする
            last->link = first; // lastを最初のノードにリンクする
            delete p;           // ノードを削除する
            
            // サイズを更新
            size--;
            return;
        }
        
        // 対象のノードまで移動
        for(int i = 1; i < n; i++)
        {
            // p,qを更新
            q = p;
            p = p->link;
        }
        
        // ノードを削除してリンクを更新
        cout << n << "th Node: " << p->data << " deleted." << endl;
        q->link = p->link;  // 前のノードと次のノードをリンクする
        
        // 末尾のとき ... lastの更新が必要
        if(n == size)
            last = q;
        
        // ノードを削除
        delete p;
        
        // サイズを更新
        size--;
    }
    
    // リストを表示する
    void Print(){
        Node *p = first;    //p = 現在地
        
        // リストが空のとき
        if(first == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        // ノードを順番に表示
        do{
            cout << p -> data << "->";
            p = p->link;
        }while(p != first);
        
        //最初のノードに戻ることを確認
        cout << p -> data << "->..." << endl;
    }
    
    // サイズを表示する
    void PrintSize()
    {
        cout << "Size: " << size << endl;
    }
};

int main()
{
    CLL list;
    
    //ノードを追加
    list.Append(5);
    list.Append(10);
    list.Append(31);
    list.Append(8);
    list.Append(1);
    list.Append(3);
    list.Append(22);
    list.Append(100);
    list.Append(7);
    
    //ノードを表示
    list.Print();
    list.PrintSize();
    
    //ノードを削除
    cout << endl;
    list.Delete(1);
    list.Delete(6);
    list.Delete(10);
    list.Delete(4);
    
    //ノードを表示
    cout << endl;
    cout << "Updated List ..." << endl;
    list.Print();
    list.PrintSize();

    return 0;
}

