import random
def drawBoard(board):
    print(board[7] + '|' + board[8] + '|' + board[9])
    print('-+-+-')
    print(board[4] + '|' + board[5] + '|' + board[6])
    print('-+-+-')
    print(board[1] + '|' + board[2] + '|' + board[3])
    print('-+-+-')

def inputPlayerLetter():
    letter = ''
    while not (letter == 'X' or letter == 'O'):
        print('Are you choosing O or X ?')
        letter = input().upper()

    if letter == 'X':
        return ['X', 'O']
    else:
        return ['O', 'X']

def whoGoesFirst():
    if random.randint(0,1) == 0:
        return 'Bot'
    else:
        return 'Person'

def makeMove(board, letter, move):
    board[move] = letter

def isWinner(b, l): # b = board, l = letter
    return \
        (
        (b[1] == l and b[2] == l and b[3] == l) or
        (b[4] == l and b[5] == l and b[6] == l) or
        (b[7] == l and b[8] == l and b[9] == l) or
        (b[7] == l and b[5] == l and b[3] == l) or
        (b[9] == l and b[5] == l and b[1] == l) or
        (b[7] == l and b[4] == l and b[1] == l) or
        (b[8] == l and b[5] == l and b[2] == l) or
        (b[9] == l and b[6] == l and b[3] == l)
        )

def getBoardCopy(board):
    boardCopy = []
    for i in board:
        boardCopy.append(i)
    return boardCopy

def isSpaceFree(board, move):
    return board[move] == ' '

def getPlayerMove(board):
    move = ' '
    while move not in '1 2 3 4 5 6 7 8 9'.split() or not isSpaceFree(board, int(move)):
        print('Your next step? (1-9)')
        move = input()
    return int(move)

def isBoardFull(board):
    for i in range(1,10):
        if isSpaceFree(board, i):
            return False

    return True


def chooseRandomMove(board, moveList):
    possibleMoves = []
    for i in moveList:
        if isSpaceFree(board, i):
            possibleMoves.append(i)

    if len(possibleMoves) != 0:
        return random.choice(possibleMoves)
    else:
        return None

def getBotMove(board, botLetter):
    if botLetter == 'X':
        playerLetter = 'O'
    else:
        playerLetter = 'X'

    for i in range(1, 10):
        boardCopy = getBoardCopy(board)
        if isSpaceFree(boardCopy, i):
            makeMove(boardCopy, botLetter, i)
            if isWinner(boardCopy, botLetter):
                return i


    for i in range(1, 10):
        boardCopy = getBoardCopy(board)
        if isSpaceFree(boardCopy, i):
            makeMove(boardCopy, playerLetter, i)
            if isWinner(boardCopy, playerLetter):
                return i

    if isSpaceFree(board, 5):
        return 5

    move = chooseRandomMove(board, [1,3,7,9])
    if move != None:
        return move

    return chooseRandomMove(board, [2,4,6,8])


print('Tic-Tac Toe')

while True:
    theBoard = [' '] * 10
    playerLetter, botLetter = inputPlayerLetter()
    turn = whoGoesFirst()
    print('\n' + turn + ' goes first.')
    gameIsPlaying = True

    while gameIsPlaying:
        if turn == 'Person':
            drawBoard(theBoard)
            move = getPlayerMove(theBoard)
            makeMove(theBoard, playerLetter, move)

            if isWinner(theBoard, playerLetter):
                drawBoard(theBoard)
                print('Well, you win!')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    drawBoard(theBoard)
                    print('White flag!')
                    break
                else:
                    turn = 'Bot'
        else:
            move = getBotMove(theBoard, botLetter)
            makeMove(theBoard, botLetter, move)

            if isWinner(theBoard, botLetter):
                drawBoard(theBoard)
                print('Bot wins! =(')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    drawBoard(theBoard)
                    print('White flag!')
                    break
                else:
                    turn = 'Person'


    print('Do you want to play again? (yes or not)')
    if not input().lower().startswith('yes'):
        break




