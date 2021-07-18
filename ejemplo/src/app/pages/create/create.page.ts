import {Component, ElementRef, OnInit, ViewChild} from '@angular/core';
import {NgForm} from '@angular/forms';
import {Router} from '@angular/router';
import {Platform} from '@ionic/angular';
import {Camera, CameraResultType, CameraSource} from '@capacitor/camera';
import { NotesService } from 'src/app/services/notes.service';

@Component({
  selector: 'app-create',
  templateUrl: './create.page.html',
  styleUrls: ['./create.page.scss']
})
export class CreatePage implements OnInit {
  photoWebviewPath: string;

  constructor(
    private router: Router,
    private noteService: NotesService,
    private platform: Platform
  ) {}

  ngOnInit() {
    // debugger;
    console.log('Platform => ', this.platform);
  }

  onSubmit(form: NgForm) {
    const title = form.value.title;
    const content = form.value.content;
    console.log({title});
    console.log({content});
    form.reset();

    // imagen random porque no tenemos donde almacenar la foto
    const image = 'https://picsum.photos/200';

    this.noteService.saveNote(title, content, image);

    this.router.navigate(['/list']);
  }

  async onPickImage() {
    const capturedPhoto = await Camera.getPhoto({
      resultType: CameraResultType.Uri,
      source: CameraSource.Camera,
      quality: 100
    });

    console.log({capturedPhoto});
    this.photoWebviewPath = capturedPhoto.webPath;
  }
}
