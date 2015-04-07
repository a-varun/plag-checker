from django.shortcuts import render, redirect

from django.http import HttpResponse

from Check.models import Tuple;

from PlagiarismChecker import settings

from check import *;

import random;
import string

def calc(a,b,c,d):
	a=int(a)
	b=int(b)
	c=int(c)
	d=int(d)
	return ((min(a,b)*2)+(min(c,d)*4))/6 #Implement int aggregation over here

def calc2(a,b):
	a=int(a)
	b=int(b)
	return min(a,b)
def index(request, requestedId=""):
	if request.method=="POST":
		##print "="*100
		##print request
		##print "="*1000
		afile = request.FILES['file1']
		##print afile.name,afile.read()
		stri = int(''.join(random.SystemRandom().choice(string.digits) for _ in xrange(6)))
		while Tuple.objects.all().filter(filesId=stri).exists():
				stri = int(''.join(random.SystemRandom().choice(string.uppercase + string.digits) for _ in xrange(6)))

		instance = Tuple(file1 = request.FILES['file1'], file2 = request.FILES['file2'], fancyId = stri)
		instance.save();
		if 'storecode' in request.POST:
			return redirect('../check/'+str(instance.fancyId))
		file1 = str(instance.file1)[2:]
		file2 = str(instance.file2)[2:]
		dire = str(settings.MEDIA_ROOT)+'/'
		ccod1 = open(dire+file1).read().split('\n')
		ccod2 = open(dire+file2).read().split('\n')
		datastuff = process_it(file1, file2, dire)
		popen3('rm '+dire+file1)
		popen3('rm '+dire+file2)
		if file1[-1]=="c":
			s_file1 = file1.replace('.c','.s')
			s_file2 = file2.replace('.c','.s')
		else:
			s_file1 = file1.replace('.cpp','.s')
			s_file2 = file2.replace('.cpp','.s')
		popen3('rm '+dire+s_file1)
		popen3('rm '+dire+s_file2)

		ccod1.insert(0,'')
		ccod2.insert(0,'')
		instance.delete()
		renderVal = {'code1' : ccod1, 'code2' :ccod2, 'ccode1': ["",datastuff[1][1]], 'ccode2':["",datastuff[1][2]],\
		 'assembly1': ["",datastuff[0][1]], 'assembly2': ["",datastuff[0][2]]}
		renderVal['title'] = 'Result'
		if datastuff[0][0][0]!=-1:
			renderVal['assemblymatch1'] = int(datastuff[0][0][0])
			renderVal['assemblymatch2'] = int(datastuff[0][0][1])
		if datastuff[0][0]<50:
			renderVal['assemblyLabel'] = 'success'
		elif datastuff[0][0]<75:
			renderVal['assemblyLabel'] = 'warning'
		else:
			renderVal['assemblyLabel'] = 'danger'
		datastuff[1][0][0]*=100
		datastuff[1][0][0]=int(datastuff[1][0][0])
		datastuff[1][0][1]*=100
		datastuff[1][0][1]=int(datastuff[1][0][1])
		renderVal['codematch1'] = datastuff[1][0][0]
		renderVal['codematch2'] = datastuff[1][0][1]
		if datastuff[0][0][0]!=-1:
			renderVal['percent'] = calc(renderVal['codematch1'],renderVal['codematch2'],renderVal['assemblymatch1'],renderVal['assemblymatch2'])
		else:
			renderVal['percent'] = calc2(renderVal['codematch1'],renderVal['codematch2'])
		if datastuff[1][0][0]<50:
			renderVal['codeLabel'] = 'success'
		elif datastuff[1][0][0]<75:
			renderVal['codeLabel'] = 'warning'
		else:
			renderVal['codeLabel'] = 'danger'
		if renderVal['percent']<50:
			renderVal['totaltitle'] = 'success'
		elif renderVal['percent']<75:
			renderVal['totaltitle'] = 'warning'
		else:
			renderVal['totaltitle'] = 'danger'

		return render(request, 'ComparedResult/ComparedResult.html', renderVal)
	elif len(requestedId) >3:
		instance = Tuple.objects.all().filter(fancyId = requestedId)[0]
		file1 = str(instance.file1)[2:]
		file2 = str(instance.file2)[2:]
		dire = str(settings.MEDIA_ROOT)+'/'
		ccod1 = open(dire+file1).read().split('\n')
		ccod2 = open(dire+file2).read().split('\n')
		datastuff = process_it(file1, file2, dire)
		ccod1.insert(0,'')
		ccod2.insert(0,'')

		renderVal = {'code1' : ccod1, 'code2' :ccod2, 'ccode1': ["",datastuff[1][1]], 'ccode2':["",datastuff[1][2]],\
		 'assembly1': ["",datastuff[0][1]], 'assembly2': ["",datastuff[0][2]]}
		renderVal['title'] = requestedId
		if datastuff[0][0][0]!=-1:
			renderVal['assemblymatch1'] = int(datastuff[0][0][0])
			renderVal['assemblymatch2'] = int(datastuff[0][0][1])
		if datastuff[0][0]<50:
			renderVal['assemblyLabel'] = 'success'
		elif datastuff[0][0]<75:
			renderVal['assemblyLabel'] = 'warning'
		else:
			renderVal['assemblyLabel'] = 'danger'
		#print '!'*100
		#print datastuff
		#print '!'*100
		datastuff[1][0][0]*=100
		datastuff[1][0][1]*=100
		renderVal['codematch1'] = int(datastuff[1][0][0])
		renderVal['codematch2'] = int(datastuff[1][0][1])
		if datastuff[1][0][0]<50:
			renderVal['codeLabel'] = 'success'
		elif datastuff[1][0][0]<75:
			renderVal['codeLabel'] = 'warning'
		else:
			renderVal['codeLabel'] = 'danger'
		if datastuff[0][0][0]!=-1:
			renderVal['percent'] = calc(renderVal['codematch1'],renderVal['codematch2'],renderVal['assemblymatch1'],renderVal['assemblymatch2'])
		else:
			renderVal['percent'] = calc2(renderVal['codematch1'],renderVal['codematch2'])
		if renderVal['percent']<50:
			renderVal['totaltitle'] = 'success'
		elif renderVal['percent']<75:
			renderVal['totaltitle'] = 'warning'
		else:
			renderVal['totaltitle'] = 'danger'


		return render(request, 'ComparedResult/ComparedResult.html', renderVal)
	else:
		return redirect('../comparecode')

	#return render(request, 'ComparedResult/ComparedResult.html', {'ccode1':["",'''<div><mark>.def __main; .scl 2; .type 32; .endef</mark><br>.LC0:<br>.ascii "Hello world\\0"<br>.text<br>.globl main<br>.def main; .scl 2; .type 32; .endef<br>.seh_proc main<br>main:<br>pushq %rbp<br>.seh_pushreg %rbp<br>movq %rsp, %rbp<br>.seh_setframe %rbp, 0<br>subq $32, %rsp<br>.seh_stackalloc 32<br>.seh_endprologue<br>call __main<br>leaq .LC0(%rip), %rcx<br>call puts<br>movl $0, %eax<br>addq $32, %rsp<br><mark>popq %rbp</mark><br><mark>ret</mark><br><mark>.seh_endproc</mark><br><mark>.def puts; .scl 2; .type 32; .endef</mark><br></div> ''']})




'''
Code from Plagiarism Detectior
Changes must be reflected here
'''


from re import match;
import difflib;
from popen2 import popen3;

def compile(file_name, dire):
	if file_name[-1]=='c':
		s_filename = dire + file_name.replace('.c','.s')
	else:
		s_filename = dire + file_name.replace('.cpp','.s')
	args = ['g++', '-S','-o', s_filename, '-w', dire+file_name ]
	##print args
	r,w,e = popen3(' '.join(args))
	s=e.read()
	if not s.lower().find('error') == -1:
		##print 'ininini'
		##print s
		return "ERROR"
	return s_filename;

def open_and_process(file_name, dire):
	filename = compile(file_name, dire)
	if filename=="ERROR":
		##print 'inopenndproc'
		return "ERROR"

	data = open(filename, "r")
	code = []
	side_data = []
	for line in data:
		while line[0]==' ' or line[0]=='\t':
			line=line[1:]
		line = line[:-1]
		#Removing stack push
		reg = "([a-zA-Z]+(\t)(-))[0-9]+(.*)"
		r = match(reg, line)
		if r:
			line = r.group(1)+"%d"+r.group(2)
		reg = "(.file)|(.section)|(.ident)|(.size).*"
		r = match(reg,line)
		if r:
			continue
		code.append(line)
	return [code,side_data]


# def get_html_markup_diflib(a,b,dif):
# 	htmla = '<div>'
# 	htmlb = '<div>'
# 	marka, markb=[0 for i in range(len(a))],[0 for i in range(len(b))]
# 	for block in dif.get_matching_blocks():
# 		l1=block[0]
# 		l2=block[2]
# 		l3=block[1]
# 		l4=block[2]
# 		for lim in range(l1,l1+l2):
# 			marka[lim]=1;
# 		for lim in range(l3,l3+l4):
# 			markb[lim]=1
# 	i=0
# 	while i<len(a):
# 		if(a[i]=="\n"):
# 			htmla+='<br>'
# 		if marka[i]==1:
# 			htmla+= '<mark>'+a[i]+'</mark>'
# 		else:
# 			htmla+= a[i]
# 		i=i+1
# 	htmla+='</div>'
# 	i=0
# 	while i<len(b):
# 		if(b[i]=="\n"):
# 			htmlb+='<br>'
# 		if markb[i]==1:
# 			htmlb+= '<mark>'+b[i]+'</mark>'
# 		else:
# 			htmlb+= b[i]
# 		i=i+1
# 	htmlb+='</div>'
## 	##print ("here")
# 	return [htmla,htmlb]

## 			##print (a[lim],end="")

def compile_and_give(file1, file2, dire):
	#would retutn the thing to display
	data1 = open_and_process(file1, dire)
	data2 = open_and_process(file2, dire)
	if data1 == "ERROR" or data2=="ERROR":
		return "ERROR"
	data1=data1[0]
	data2=data2[0]
	for i in range(len(data1)):
		data1[i]=data1[i].replace('\t',' ')
	for i in range(len(data2)):
		data2[i]=data2[i].replace('\t',' ')
	return get_html_markup(data1,data2)
		
def process_it(file1, file2, dire):

	#for gcc, you got to create the .s file  at dire
	assembly = compile_and_give(file1, file2, dire)
	if assembly=="ERROR":
		assembly=[1,1,1]
		assembly[0]=[-1,-1]
		assembly[1]="<mark>ERROR!</mark>"
		assembly[2]="<mark>ERROR!</mark>"
	#print obtain_codediff(dire+file1, dire+file2)
	return [assembly, obtain_codediff(dire+file1, dire+file2)]

def get_html_markup(a,b):
	dp=[]	
	for i in xrange(len(a)):
		p=[]
		for j in xrange(len(b)):
			p.append(0)
		dp.append(p)
	i=0
	j=0
	while i<len(a):
		j=0
		while(j<len(b)):
			maxi=0
			if not i==0:
				maxi=max(maxi,dp[i-1][j])
			if not j==0:
				maxi=max(maxi,dp[i][j-1])
			if a[i]==b[j]:
				if i>0 and j>0:
					maxi=max(maxi, dp[i-1][j-1]+1)
				else:
					maxi=1
			dp[i][j]=maxi
			j+=1
		i+=1
	if len(a)==0 or len(b)==0:
		htmla = '<div>'
		htmla+= '<br>'.join(a)
		htmla+= '</div'
		htmlb = '<div>'
		htmlb+= '<br>'.join(b)
		htmlb+= '</div'
		return [[0,0], htmla, htmlb]
	htmla = '<div>'
	stk=[]
	stk.append((i-1,j-1))
	marka, markb=[0 for i in range(len(a))],[0 for i in range(len(b))]
	while True:
		x,y = stk.pop()
		if x<0 or y<0:
			break
		elif(a[x]==b[y]):
			marka[x]=1
			markb[y]=1
			stk.append((x-1, y-1))
		elif x==0:
			stk.append((x,y-1))
		elif y==0:
			stk.append((x-1,y))
		else:
			stk.append((x-1,y) if dp[x][y]==dp[x-1][y] else (x,y-1))

	i=0
	while i<len(a):
		if marka[i]==1:
			htmla+= '<mark>'+a[i]+'</mark><br>'
		else:
			htmla+= a[i]+'<br>'
		i+=1
	i=0
	htmla+='</div>'
	htmlb = '<div>'
	while i<len(b):
		if markb[i]==1:
			htmlb+= '<mark>'+b[i]+'</mark><br>'
		else:
			htmlb+= b[i]+'<br>'
		i+=1
	htmlb+='</div>'
	return [[((dp[-1][-1]*1.0)/len(a))*100,((dp[-1][-1]*1.0)/len(b))*100],htmla,htmlb]
		
