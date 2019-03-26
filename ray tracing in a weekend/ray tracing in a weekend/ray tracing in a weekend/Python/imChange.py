from PIL import Image
import PythonMagick as PM

def ppmTojpg(path):
	path=path+'\\example2.ppm'
	print(path)	
	file=open(path)
	print(file.readline())
	edge=file.readline().split(" ")
	x=edge[0]
	y=edge[1]
	print(x+","+y)
	im=Image.new("RGB",(int(y),int(x)))
	for i in range(0,int(y)):
		for j in range(0,int(x)):
			line = file.readline()
			rgb = line.split(' ')#分离rgb
			#print(len(rgb))
			if len(rgb)==3:
				im.putpixel((i,j),(int(rgb[0]),int(rgb[1]),int(rgb[2]))) #rgb转化为像素
			
	#im.show()
	#im_rotate=im.rotate(90)
	im_fh=im.transpose(Image.FLIP_LEFT_RIGHT)
	im_fh.show()
