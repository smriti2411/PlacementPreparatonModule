 int findCeil(Node root, int key) {
        int result = Integer.MAX_VALUE;
        while(root!=null){
            if(root.data == key){
                return key;
            }else if(root.data>key){
                result = root.data;
                root = root.left;
            }else{
                root = root.right;
            }
        }
        return result;
    }