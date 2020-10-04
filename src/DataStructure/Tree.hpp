#include "Node.hpp"

#pragma once

namespace mlib {
    
    // Tree Node
    template<typename T>
    class TNode : mlib::Node<T> {
        public:
            TNode<T>& parent() const;
            TNode<T>& children() const;
            bool isRoot();
            bool isExternal();
    };

    
    template<typename T>
    class Tree {
        public:
            virtual index_t size();
            virtual bool empty();
            virtual index_t root();
    }
};