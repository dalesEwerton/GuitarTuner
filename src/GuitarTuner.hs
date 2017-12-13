
import Control.Monad ( unless )
import System.Exit ( exitWith, ExitCode(ExitSuccess) )
import Graphics.UI.GLUT hiding ( initialize )

-- coordenadas botoes
botoes:: [(GLfloat,GLfloat,GLfloat)]
botoes = [ (sin (2*pi*k/12), cos (2*pi*k/12), 0) | k <- [1..12] ]

-- funcao que mostra o menu de "exit" 
initialize :: IO ()
initialize = do
   attachMenu RightButton (Menu [MenuEntry "Exit" (exitWith ExitSuccess)])
   depthFunc $= Just Less

funcaoMouse :: KeyboardMouseCallback
funcaoMouse (MouseButton RightButton)_ _ _ = exitWith ExitSuccess
funcaoMouse (Char 'x')              _ _ _ = exitWith ExitSuccess
funcaoMouse _                       _ _ _ = postRedisplay Nothing

-- limpar o buffer da tela
reshape :: ReshapeCallback
reshape size@(Size width height) =
   unless (height == 0) $ do
      viewport $= (Position 0 0, size)
      matrixMode $= Projection
      loadIdentity
      perspective 90 (fromIntegral width / fromIntegral height) 1 100

      matrixMode $= Modelview 0

display :: DisplayCallback
display = do
  clear [ColorBuffer]
  -- coloca os botoes na tela 
  renderPrimitive Points $
     mapM_ (\(x, y, z) -> vertex $ Vertex3 x y z) botoes
  flush

main :: IO ()
main = do
   _ <- getArgsAndInitialize

   initialWindowSize $= Size 1024 768
   initialWindowPosition $= Position 100 150
   _ <- createWindow "GuitarTuner"
   
   initialize

   displayCallback $= display
   reshapeCallback $= Just reshape
   keyboardMouseCallback $= Just funcaoMouse
   mainLoop