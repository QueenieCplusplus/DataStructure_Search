//1216, 15:00, by Queenie



// Definition
// each internal nod is a 2node or 3node
// a two node has 1 ele
// a three node has 2 ele
// external modes are at the same level


template<class KT> 
class Node {

    friend class Nodes<KT>;
    private:
        Element<KT> dP, dQ;
        Node *lChild, *mChild, *rChild;
};

template<class KT> 
class Nodes {
    private:
        Node<KT> *root;
        KT maxKey;

    public:
        Nodes(KT max, Node<KT> *init = 0): maxKey(max), root(init) {}; 

        bool insertPQ(const Element<KT> &);
        bool deletePQ(const Element<KT> &)
        Node<KT>* search(const Element<KT> &);
};

// Search

// search for the ele x, if not exist, then return 0
// otherwise, return a pointer to the node.
template<class KT>
Node<KT>* Node<KT>::search(const Element<KT> & x)
{
  for(Node<KT>* pq = root; pq;)
     switch(pq->compare(x)){

        case 1: pq = pq->lChild; break;
        case 2: pq = pq->mChild; break;
        case 3: pq = pq->rChild; break;
        case 4: return pq; 
     }
} 