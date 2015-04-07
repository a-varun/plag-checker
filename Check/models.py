from django.db import models

# Create your models here.

class Tuple(models.Model):
	file1 = models.FileField()
	file2 = models.FileField()
	filesId = models.AutoField(primary_key=True)
	fancyId = models.IntegerField()
