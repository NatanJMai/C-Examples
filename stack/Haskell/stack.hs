data Node  = Node  {id_   :: Integer} deriving (Show)
data Stack = Stack {nodes :: [Node]}  deriving (Show)

st :: Integer -> [Node]
st 0 = []
st x = [Node x] ++  st(x-1)

test001 :: Integer -> Stack
test001 x = Stack (st x)

printF :: Stack -> [Integer]
printF x = 
    [(id_ n) | n <- (nodes x)]


