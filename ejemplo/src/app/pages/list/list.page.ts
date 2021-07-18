import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { ModalController } from '@ionic/angular';
import { ViewNoteComponent } from 'src/app/components/view-note/view-note.component';
import { NotesService } from 'src/app/services/notes.service';
import { Note } from 'src/app/types/models';

@Component({
  selector: 'app-list',
  templateUrl: './list.page.html',
  styleUrls: ['./list.page.scss'],
})
export class ListPage implements OnInit {
  notes: Note[] = [];

  constructor(
    private noteService: NotesService,
    public modalController: ModalController,
    private router: Router) {}

  ngOnInit() {
    //Sacamos las notas del servicio de notas
    this.notes = this.noteService.notes;
    console.log(this.notes);
  }

  async viewNote(noteId: number) {
    console.log('note: ' + noteId);
    const modal = await this.modalController.create({
      component: ViewNoteComponent,
      componentProps: {
        noteId
      }
    });
    return await modal.present();
  }

  goToEdit(noteId: number) {
    this.noteService.currentNote = noteId;
    this.router.navigate(['/edit']);
  }

  deleteNote(nodeId: number){
    this.noteService.deleteNote(nodeId);
  }
}
