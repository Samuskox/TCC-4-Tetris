while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if not gameOverRunning:
        fallTimer += dt
        if fallTimer >= fallInterval:
            #print("1 second")
            fallTimer = 0
            if grid.piece.isValidMove(Vector2(0,1)):
                grid.piece.move(Vector2(0,1))

        if grid.piece.isValidMove(Vector2(0,1)):
            lockTimer = 0
        else:
            lockTimer += dt
            if lockTimer >= lockInterval:
                grid.lockPiece()
                grid.spawnPiece()
                lockTimer = 0

    dt = clock.tick(60) / 1000

pygame.quit()