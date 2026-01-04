package a_general;

import java.util.*;

public class Collections_Algorithms {

    class Interval{
        int x;
        int y;
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
    }

    static void math(){
        Math.min(Math.min(4, 3), Math.min(2, 1));
        Math.max(Math.max(4, 3), Math.max(2, 1));

        Math.ceil(0.001);   // 1.0
        Math.floor(0.001);  // 0.0
        Math.abs(-100);       // 100
        Math.sqrt(2);
        Math.pow(2, 2);
    }

    static void comparators(){
        Comparator<Integer> basic = (x, y) -> Integer.compare(x, y);

        Comparator<Integer> basicv2 = Comparator.naturalOrder();

        Comparator<Integer> basicReverse = Comparator.reverseOrder();

        Comparator<Interval> intervalV1 = Comparator
        .comparingInt(Interval::getX)
        .thenComparingInt(Interval::getY);

        Comparator<Interval> intervalV2 = Comparator
        .comparingInt(Interval::getX)
        .reversed()
        .thenComparingInt(Interval::getY);

        Comparator<Interval> intervalV3 = Comparator
        .comparingInt(Interval::getX)
        .thenComparingInt(Interval::getY)
        .reversed();
    }

    static void collectionContainers(){
        /*
            Collection -> Queue, Deque, Set, List
        */
       Queue<Integer> minHeap = new PriorityQueue<>();  new PriorityQueue<>(List.of(1, 2, 3));
       Queue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

       minHeap.size(); 
       minHeap.peek(); 
       minHeap.poll(); 
       minHeap.offer(1);
       minHeap.clear();


       Deque<Integer> arrayDeque = new ArrayDeque<>();  new ArrayDeque<>(List.of(1, 2, 3));

       arrayDeque.size();
       arrayDeque.peekFirst(); arrayDeque.peekLast();
       arrayDeque.pollFirst(); arrayDeque.pollLast();
       arrayDeque.offerFirst(1); arrayDeque.offerLast(2);
       arrayDeque.clear();

       TreeMap<Integer, String> treeMap = new TreeMap<>();  new TreeMap<>(Comparator.reverseOrder());
       new TreeMap<>(Map.ofEntries(Map.entry(1, "Akshay")));

       treeMap.size();
       treeMap.put(1, "Akshay");
       treeMap.get(1);
       treeMap.containsKey(1);

       treeMap.firstEntry(); treeMap.lastEntry();
       treeMap.ceilingEntry(1); treeMap.floorEntry(1);
       treeMap.higherEntry(1); treeMap.lowerEntry(1);

       treeMap.headMap(1, true);
       treeMap.tailMap(1, true);
       treeMap.subMap(1, true, 4, true);

       treeMap.entrySet(); treeMap.descendingMap();

       treeMap.remove(1); treeMap.pollFirstEntry(); treeMap.pollLastEntry();
       treeMap.clear();


       TreeSet<Integer> treeSet = new TreeSet<>();  new TreeSet<>(Comparator.reverseOrder());   new TreeSet<>(List.of(1, 2, 3));

       treeSet.size();
       treeSet.add(1);
       treeSet.contains(1);
       

       treeSet.first(); treeSet.last();
       treeSet.ceiling(1); treeSet.floor(2);
       treeSet.higher(1); treeSet.lower(2);

       treeSet.descendingSet();

       treeSet.remove(1); treeSet.pollFirst(); treeSet.pollLast();
       treeSet.clear();


       Map<Integer, String> hashMap = new HashMap<>();  new HashMap<>(Map.ofEntries(Map.entry(1, "Akshay")));

       hashMap.size();
       hashMap.put(1, "Akshay");
       hashMap.containsKey(1);
       hashMap.remove(1);
       hashMap.entrySet();
       hashMap.clear();


       Set<Integer> hashSet = new HashSet<>();  new HashSet<>(List.of(1, 2, 3));

       hashSet.size();
       hashSet.add(1);
       hashSet.contains(1);
       hashSet.remove(1);
       hashSet.clear();;

       List<Integer> arrayList = new ArrayList<>(); new ArrayList<>(List.of(1, 2, 3));

       arrayList.size();
       arrayList.add(1);
       arrayList.set(0, 34);
       arrayList.get(0);
       arrayList.remove(0); // Removes element at index 1, as primitive 1 is passed
       arrayList.remove(Integer.valueOf(12)); // Removes element with value 12, as Integer obj is passed
       arrayList.clear();
    }

    static void collectionAlgorithms(){
        List<Integer> list = List.of(1, 2, 3, 4, 5);

        Collections.min(list);  Collections.min(list, Comparator.naturalOrder());
        Collections.max(list);  Collections.max(list, Comparator.naturalOrder());

        Collections.sort(list); Collections.sort(list, Comparator.reverseOrder());

        /*
            If there are multiple occurrence of element can point to any. 
            And if element not present return -(insertion point) - 1 or Collection.size id all elements are smaller
        */
        Collections.binarySearch(list, 2);  Collections.binarySearch(list, 2, Comparator.naturalOrder());

        Collections.reverse(list);

        Collections.frequency(list, 2);
    }

    static void setOperations(){
        List<Integer> A = List.of(1, 2, 2);
        List<Integer> B = List.of(2, 3, 4);

        System.out.println("A:" + A + " B:" + B);

        List<Integer> union = new ArrayList<>(A);
        union.addAll(B);

        System.out.println("Union:" + union); // [1, 2, 2, 2, 3, 4]

        List<Integer> intersection = new ArrayList<>(A);
        intersection.retainAll(B);

        System.out.println("Intersection:" + intersection); // [2, 2]

        List<Integer> diff = new ArrayList<>(A);
        diff.removeAll(B);

        System.out.println("Difference:" + diff); // [1]

        List<Integer> set = new ArrayList<>(A);
        boolean isSubset = set.containsAll(B);

        System.out.println("isSubset:" + isSubset);  // false

    }

    static void arrays(){
        int[] arr = new int[]{5, 4, 3, 2, 1};

        Arrays.sort(arr);   Arrays.sort(arr, 0, arr.length);

        Arrays.binarySearch(arr, 1);    Arrays.binarySearch(arr, 0, arr.length, 1);

        Arrays.fill(arr, -1);
    }
    
    public static void main(String[] args) {
        // math();
        // comparators();
        // collectionContainers();
        // collectionAlgorithms();
        // setOperations();
        // arrays();
    }
}
