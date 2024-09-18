This repo seeks help , i upload the codes that dont work.
IN FILTER , the mathematical average of RGB values of a pixel doesnt correspond to the true value under the hood of BLUR  function. the average has to be calculated taking seperately all rgb values of all the immediate neighbours of the pixel.
blur function uses BOX BLUR algo. 
In case if you feel boared, you can also modify filter into boundary function using sobel operator on image[i][j] for all i,j.
