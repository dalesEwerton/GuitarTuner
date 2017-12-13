
import Graphics.UI.GLUT
import Control.Monad


botoes:: [(GLfloat,GLfloat,GLfloat)]
botoes = [ (sin (2*pi*k/12), cos (2*pi*k/12), 0) | k <- [1..12] ]

main :: IO ()
main = do
  (_progName, _args) <- getArgsAndInitialize
  initialWindowSize $= Size 1024 768
  initialWindowPosition $= Position 100 150
  _window <- createWindow "GuitarTuner"
  displayCallback $= display
  mainLoop
 
display :: DisplayCallback
display = do
  clear [ColorBuffer]
  renderPrimitive Points $
     mapM_ (\(x, y, z) -> vertex $ Vertex3 x y z) botoes
  flush