int chk_depth(node *temp){
	        if (temp==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = chk_depth(temp->left);
       int rDepth = chk_depth(temp->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}