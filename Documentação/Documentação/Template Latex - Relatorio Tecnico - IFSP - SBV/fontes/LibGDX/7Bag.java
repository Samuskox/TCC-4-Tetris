public int getNextPieceNum() {
    System.out.println(bagPieces);
    if (bagPieces.isEmpty()) {
        refillPieceQueue();
    }
    return bagPieces.remove(0);
}

public void refillPieceQueue() {
    bagPieces.add(1);
    bagPieces.add(2);
    bagPieces.add(3);
    bagPieces.add(4);
    bagPieces.add(5);
    bagPieces.add(6);
    bagPieces.add(7);
    Collections.shuffle(bagPieces);
}