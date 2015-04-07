# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Tuple',
            fields=[
                ('file1', models.FileField(upload_to=b'')),
                ('file2', models.FileField(upload_to=b'')),
                ('filesId', models.AutoField(serialize=False, primary_key=True)),
                ('fancyId', models.IntegerField()),
            ],
            options={
            },
            bases=(models.Model,),
        ),
    ]
