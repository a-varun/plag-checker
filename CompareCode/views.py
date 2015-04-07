from django.shortcuts import render

from django.http import HttpResponse

from django.template import RequestContext


def showCompare(request):
    context = {'latest_question_list': 'something'}
    return render(request, 'CompareCode/CompareCode.html', context,context_instance=RequestContext(request))