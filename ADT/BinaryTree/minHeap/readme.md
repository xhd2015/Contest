
a min heap that has a perfect quality,that child of a point x is 2*x,2x+1,and root is x/2
there is two basic operatons on it,like insert an element and delete the top element

for this first operation,we can insert the new one to the last+2,and then use up-find() to make it in a proper location.But there is a problem,how will it be if the element is repeating?so we have another stratage that,we do not change last,we assume there is an empty hole binding with a value-element.so we try to up-find the location and if one is finded,we change it until it is the same or cannot cahnge more.

for the second operation,we make the last element to the first,and let last subtrate 1.the use down-find to locate it,which is similar to up-find.



actually,to judge if an element exists in a heap is so diffculty,so heap must allow repeated element.<F5>
